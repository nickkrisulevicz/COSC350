#Nick Krisulevicz
#COSC 350 - Lab E1R
#03/03/2022
#task5.sh

#!/bin/bash

echo -e "Variable assigned with \$variablename \n"

foo=10
x=foo
y=\$$x
echo $y

echo -e "\nVariable assigned with eval command \n"
foo=10
x=foo
eval y=\$$x
echo $y

exit 0;

