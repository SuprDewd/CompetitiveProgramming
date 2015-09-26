function dvorak {
    setxkbmap -option caps:escape dvorak is
    xset r rate 150 100
    set -o vi
}
alias "h.soav"="dvorak"
function james {
    setxkbmap en_US
}
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
