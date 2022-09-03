#!/bin/bash
# time keeps changing when dual booting win/linux
timedatectl set-local-rtc 1 --adjust-system-clock &
# swap + and =
sudo xmodmap -e "keycode 21 = plus equal" &

dwm_streamdeck &
dwm_investment &
dwm_news &
