#!/bin/bash
# time keeps changing when dual booting win/linux
timedatectl set-local-rtc 1 --adjust-system-clock &

sd-streamdeck &
sd-investment &
sd-news &
