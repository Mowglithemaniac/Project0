# Here we're using the date command 'day' output.
#!/bin/bash
case $(date +%a) in
    "Mon" | "Wed")
        echo "Day is uneven"
        ;;
    "Tue" | "Thu")
        echo "Day is even"
        ;;
    "Fri")
        echo "Almost weekend"
        ;;
    *)
        echo "Either it's weekend, or I screwed up"
        ;;
esac