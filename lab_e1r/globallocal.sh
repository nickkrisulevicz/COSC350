#Nick Krisulevicz
#COSC 350 - Lab E1R
#03/03/2022
#globallocal.sh

#! /bin/sh

LocalGlobal ()
{
	local loc_var=23
	echo "\"loc_var\" in function = $loc_var"
	global_var=999
	echo "\"global_var\" in function = $global_var"
}

LocalGlobal
echo "\"loc_var\" outside function = $loc_var"
echo "\"global_var\" outside function = $global_var"

exit 0

