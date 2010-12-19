##Dirs and files of system
    ./.config/user-dirs.dirs change path of desktop.
    /etc/fstab to mount disk automatically.
##cp [option]
    -a, --archive      copy files includeing ownerships and permissions.
    -i, --interactive  ask for whether overwrite the exist file.
    -r, --recursive    used when copy a directory and all of it's contents.
    -u, --update       only copy new files. 
    -v, --verbose      display the informative messages when copying.
##mv shares the same option as cp.
##rm [option]
    -i, --interactive  same as above.
    -r, --recursive    specified when deleting an unempty directory.
    -f, --force        force delete.
    -v, --verbose      same as above.
##Look out when wildcard used with rm.
    rm * .html
    the bash will delete all the files and then complain there is no html file.
##ln
    ln file link     to create a hard link
    ln -s item link  to create a symbolic link either a file or a directory.
    tips:
        1.a hard link cannot in different file systems,and wherever the file is moved to,the link can find it.
        2.a hard link can not referance to a directory.
#Bash
    1.press K on a keyword to view the MAN page.
    2.1>&2 redirect 1(stdout) to 2(stderr)
    3.echo -n not output new line
    4.variable:-y  if the variable is NULL,then assign y to the variable
        e.g:
        echo -n "Want to say hello(Y/n): "
        read Choice
        if [ "${Choice:-y}" = "y" ];then
            echo hello
        fi
    5.source + .sh to run the script in current process.
##read
    read -e ignore the '\n' or '\0' at the tail when input is NULL
##if quote
###if then fi
    if [ condition ]
    then
        statements
    fi
###if then else fi
    if [ condition ]
    then
        statements
    else
        statements
    fi
###if elif else fi
    if [ condition ]
    then
        statements
    elif [ condition ]
    then
        statements
    else
        statements
    fi
###if then else if then fi fi
    if [ condition1 ]
    then
        statements
    else
        if[ condition2 ]
        then
            statements
        fi
    fi
###test
    if [ condition ]
    if [ ! conditon ]
##Search
###which
    which command
    search the location of a command
###locate
    search filename in database (very fast)
    locate filename
###find
    find PATH
    find . -name "filename"
    find .|grep string
###grep
    grep [string] [filename]
    grep -i ignore case
    grep -n show line number
    find . -exec grep "$1" '{}' \; -print 
    -exec call command in find
##dpkg
    dpkg -l   list all package installed
    dpkg -L   list the files in the package
    dpkg -S   show which package does the file belonging to
    dpkg -r --remove
    dpkg -P --purge
##apt-get
    apt-get -remove  not remove configuration files
    apt-get -purge   remove all the files
#websites
    hacker news
    stack overdev
