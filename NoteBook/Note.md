### ./.config/user-dirs.dirs change path of desktop.
### a == &a[0].
### getchar() will get the '\n',so add an extra getchar() to avoid errors.
### /etc/fstab to mount disk automatically.
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
        2.a hard link my not referance to a directory.

