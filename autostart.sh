#!/bin/bash
( exec  "/suckless/dwmblocks/dwmblocks") &
( exec "code" ) & 
( exec "thunderbird" ) & 
( exec "steam" ) & 
( exec "spotify" ) & 


# activating
st -e xdotool keydown Alt key n keyup Alt &