xset r rate 150 100
set -o vi

function check {
  IFS=
  s=""
  cat $1 | while read l; do
    s="$s$(echo $l | sed 's/\s//g')\n"
    h=$(echo -ne "$s" | md5sum)
    echo "${h:0:2}  $l"
  done
}
# setxkbmap -option caps:escape dvorak is
# setxkbmap en_US
alias c='cd'
alias l='ls -lh'
alias la='ls -lah'
# vim: cc=60 ts=2 sts=2 sw=2:
