#!/bin/bash

# Compositor
picom -f &

#logout
light-locker &

# Change language
setxkbmap -option grp:alt_space_toggle fo,us &

xrandr --output DP-1-1 --primary --mode 1920x1080 --rate 119.98 --output eDP-1-1 --mode 1920x1080 --rate 59.98 --left-of DP-1-1 &

# Wallpaper
nitrogen --restore &
~/.local/bin/dwmblocks &
# VPN
nordvpn c &
( exec  "/suckless/dwmblocks/dwmblocks") &
( exec "code" ) & 
( exec "thunderbird" ) &
( exec "steam" ) & 


# activating
st -e xdotool keydown Alt key n keyup Alt &