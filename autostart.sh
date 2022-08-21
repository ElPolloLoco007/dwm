#!/bin/bash
# time keeps changing when dual booting win/linux
timedatectl set-local-rtc 1 --adjust-system-clock &
tilda &
dwm_streamdeck &
dwm_investment &
dwm_news &
