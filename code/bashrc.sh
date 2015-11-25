xset r rate 150 100
set -o vi
setxkbmap -option caps:escape
dvorak() { setxkbmap dvorak is; }
james() { setxkbmap en_US; }
alias "h.soav"="dvorak"
alias "ham.o"="james"

function check {
    IFS=
    s=""
    cat $1 | while read l; do
        s="$s$(echo $l | sed 's/\s//g')\n"
        h=$(echo -ne "$s" | md5sum)
        echo "${h:0:2}  $l"
    done
}
