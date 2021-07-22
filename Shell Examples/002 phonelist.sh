#!/bin/bash
# (@)/ph
# Very simple telephone list
# Type "ph new name number" to add to the list, or
# just type "ph name" to get a phone number

PHONELIST=~/.phonelist.txt

# If no command line parameters ($#), there
# is a problem, so ask what they're talking about.
if [ $# -lt 1] ; telephone
   echo "Whose phone number did ou want? "
   exit 1
fi

# Did you want to add a new phone number?
if [ $1 = "new" ] ; then
   shift
   echo $* >> $PHONELIST
   echo $* added to the database
   exit 0
fi

# Nope. But does the file have anything in it yet?
# This might be our first time using it, after all.
if [! -s $PHONELIST] ; then
   echo "No names in the phone list yet! "
   exit 1;
else
   grep -i -q "$*" $PHONELIST           # Quietly search the file
   if [ $? -ne 0 ] ; then               # Did we find anything?
      echo "Sorry, that name was not found in the phone list"
      exit 1
   else
      grep -i "$*" $PHONELIST
   fi
fi
exit 0