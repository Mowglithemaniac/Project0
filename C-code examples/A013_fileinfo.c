/*============================================================================
 Name        : fileinfo.c
 Author      : Declined
 Version     : 1.00
 Date        : 21/09-2023
 Description : Looking at file metadata
 ============================================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>

/** Function Prototypes **/
void printing(struct stat *buffer, char argument[]);
void filename(char argument[]);
char filetype(int mode);
void permissions(int mode);
void ownership_user(unsigned int userid);
void ownership_group(unsigned int groupid);
//raw metadata
void links(int links);
void display_inode(unsigned long inode_id);
void date_info(struct stat *buffer);
void size_info(struct stat *buffer);
void device_info(struct stat *buffer);
void mode_info(int mode);


// Colors
void print_red();
void print_yellow();
void print_green();

int main(int argc, char *argv[]){
    struct stat buffer;
    if(argc-2){
        fprintf(stderr, "\x1b[31m[!]\x1b[0m Incorrect usage, requires an argument!\n");
        fprintf(stderr, "%s <filename>\n", argv[0]);
        return 1;
    }
    if(stat(argv[1], &buffer)){
        fprintf(stderr, "\x1b[31m[!]\x1b[0m File \"%s\" does not exist.\n", argv[1]);
        return EXIT_FAILURE;
    }
    printing(&buffer, argv[1]);
    return 0;
}

void printing(struct stat *buffer, char argument[]){
    // Primary information {filename, file type, permissions}
    printf("\x1b[34m[*]\x1b[0m Primary information\n");
    filename(argument);
    filetype(buffer->st_mode);
    permissions(buffer->st_mode);
    ownership_user(buffer->st_uid);
    ownership_group(buffer->st_gid);

    //Extended information
    printf("\n\x1b[34m[*]\x1b[0m Exended information\n");
    links(buffer->st_nlink);
    device_info(buffer);
    display_inode(buffer->st_ino);
    mode_info(buffer->st_mode);
    size_info(buffer);
    date_info(buffer);

}


void filename(char argument[]){
    int length = strlen(argument);
    char name[length];
    int slash = -1;
    for(int i = 0; i < length; i++){
        if(argument[i]== '/')
            slash = i;
    } 
    if (slash != -1){

        for(int i = slash+1 , a = 0; i < length; i++, a++){
            name[a] = argument[i];
        }
        name[length] = '\0';
    }
    else
        strcpy(name, argument);
    print_green();
    printf("File name\t-> %s\n", name);
}

void permissions(int mode){
    //If any executable flags, then print yellow, else green
    ((int)0x49 & mode) ? 
        print_yellow():
        print_green();
    printf("Permissions\t-> ");

    printf("%c%c%c%c%c%c%c%c%c\n",
    mode & __S_IREAD   ? 'r' : '-',
    mode & __S_IWRITE  ? 'w' : '-',
    mode & __S_ISUID   ? (mode & __S_IEXEC)? 's' :  'S' : (mode & __S_IEXEC)? 'x' :  '-',
    mode & S_IRGRP     ? 'r' : '-',
    mode & S_IWGRP     ? 'w' : '-',
    mode & __S_ISGID   ? (mode & S_IXGRP) ? 's' : 'S' : (mode & S_IXGRP)? 'x' : '-',
    mode & S_IROTH     ? 'r' : '-',
    mode & S_IWOTH     ? 'w' : '-',
    mode & __S_ISVTX   ? (mode & S_IXOTH) ? 't' : 'T' : (mode & S_IXOTH)? 'x' : '-'
    );
}

char filetype(int mode){
    char filetype;
    print_green();
    printf("File type\t-> ");
    //All file mode bits are found at location 0xF000
    switch(mode & __S_IFMT){ // These bits to be exact: 0xF000
        case __S_IFDIR: // Directory, 0x4000
            printf("Directory\n");
            filetype = 'd';
            break;
        case __S_IFLNK: // 0xA000 - Symbolic link
            printf("Symbolic link\n");
            filetype = 'l';
            break;
        case __S_IFREG: // 0x8000 - Regular file
            printf("Regular file\n");
            filetype = '-';
            break;
        case __S_IFCHR: // 0x2000 - Character Special File
            printf("Character Special File\n");
            filetype = 'c';
            break;
        case __S_IFBLK: // 0x6000 - Block Special File
            printf("Block Special File\n");
            filetype = 'b';
            break;
        case __S_IFIFO: // 0x1000 - FIFO or Named Pipe
            printf("FIFO or Named Pipe\n");
            filetype = 'p';
            break;
        case __S_IFSOCK:// 0xC000 - Socket
            printf("Socket\n");
            filetype = 's';
            break;
        default:        // Should not be possible, unknown format
            printf("Unknown file format\n");
            filetype = '?';
    }
    return filetype;
}


void ownership_user(unsigned int file_owner_id){
    struct passwd *pwinfo;
    pwinfo   = getpwuid(file_owner_id);
    int real_id = getuid(), effective_id = geteuid(), result = 0;
// Check if the user is pretending to be someone else
// And also verify that it is indeed the users own file
    (real_id != effective_id) | 
    (real_id != file_owner_id) ?
        print_yellow():
        print_green() ;
    printf("File owner\t-> %s\n", pwinfo->pw_name);
}

/**
 * Due to greatly varied configurations on different systems
 * it is a greater than necessary task to compare the effective_user's
 * group, against the group which the file is a part of.
*/
void ownership_group(unsigned int groupid){
    struct group *group_data;
    group_data = getgrgid(groupid);
    print_green();
    printf("Group owner\t-> %s\n", group_data->gr_name);
}


/**** Raw information ***/


void links(int links){
    (links == 1) ? 
        print_green(): // 1 link, green
        print_yellow(); // Other than 1 link, yellow
    printf("Links\t-> %d\n", links);
}

void display_inode(unsigned long inode_id){
    print_green();
    printf("Inode\t-> %ld\n", inode_id);
}

void size_info(struct stat *buffer){
    print_green();
    printf("Size information:\n");
    printf("   -> Size (bytes)\t-> %d\n", buffer->st_size);
    printf("   -> Blocks used\t-> %d\n", buffer->st_blocks);
    printf("   -> Block size\t-> %d\n", buffer->st_blksize);
}

void date_info(struct stat *buffer){
    print_green();
    time_t tmpvalue;
    printf("Time information:\n");
    printf("   -> Last access\t-> %s", ctime(&buffer->st_atime));
    printf("   -> Last modified\t-> %s", ctime(&(buffer->st_mtime)));
    printf("   -> Last status change-> %s", ctime(&(buffer->st_ctime)));
}

/**
 * It isn't possible to do a reverse lookup
 * by using the device_id to find the device.
 * Instead all devices have to be queried,
 * extract their ID's and then compare against
 * the previously gathered ID.
*/
void device_info(struct stat *buffer){
    print_green();
    printf("Device ID\t-> %ld\n", buffer->st_dev);
}

void mode_info(int mode){
    print_green();
    printf("Mode info\t-> {snip}_%c%c%c%c_%c%c%c_%c%c%c_%c%c%c_%c%c%c\n",
// Bits used for file-mode
        mode & 0x8000      ? '1' : '0',
        mode & 0x4000      ? '1' : '0',
        mode & 0x2000      ? '1' : '0',
        mode & 0x1000      ? '1' : '0',
// Bits for SUID, SGID, Sticky bit respectively
        mode & __S_ISUID   ? '1' : '0',
        mode & __S_ISGID   ? '1' : '0',
        mode & __S_ISVTX   ? '1' : '0',
// Bits for READ, WRITE, EXECUTE for owner
        mode & __S_IREAD   ? '1' : '0',
        mode & __S_IWRITE  ? '1' : '0',
        mode & __S_IEXEC   ? '1' : '0',
    // Bits for READ, WRITE, EXECUTE for group
        mode & S_IRGRP     ? '1' : '0',
        mode & S_IWGRP     ? '1' : '0',
        mode & S_IXGRP     ? '1' : '0',
    // Bits for READ, WRITE, EXECUTE for other
        mode & S_IROTH     ? '1' : '0',
        mode & S_IWOTH     ? '1' : '0',
        mode & S_IXOTH     ? '1' : '0'
     );
}


/******* COLORS *********/

void print_red(){
    printf("\x1b[31m[+]\x1b[0m ");
}
void print_yellow(){
    printf("\x1b[33m[+]\x1b[0m ");
}
void print_green(){
    printf("\x1b[32m[+]\x1b[0m ");
}

/************************
 * Background information needed to understand
 * the concepts being used.

struct stat{
    __dev_t st_dev;		    // Device.
    __ino_t st_ino;		    // File serial number
    __nlink_t st_nlink;		// Link count.
    __mode_t st_mode;		// File mode.
    __uid_t st_uid;		    // User ID of the file's owner
    __gid_t st_gid;		    // Group ID of the file's group
    int __pad0;             // 
    __dev_t st_rdev;		// Device number, if device.
    __off_t st_size;		// Size of file, in bytes.
    __blksize_t st_blksize;	// Optimal block size for I/O.
    __blkcnt_t st_blocks;	// Number 512-byte blocks allocated
}

// A record in the user database.  
struct passwd{
  char *pw_name;		// Username.
  char *pw_passwd;		// Hashed passphrase, if shadow database
                        // not in use (see shadow.h).
  __uid_t pw_uid;		// User ID.
  __gid_t pw_gid;		// Group ID.
  char *pw_gecos;		// Real name.
  char *pw_dir;			// Home directory.
  char *pw_shell;		// Shell program.
}

// The group structure.
struct group{
    char *gr_name;	    // Group name.
    char *gr_passwd;    // Password.
    __gid_t gr_gid;	    // Group ID.
    char **gr_mem;	    // Member list.
}

*/