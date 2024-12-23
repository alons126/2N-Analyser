#!/bin/bash

echo "- Re-pulling repository -----------------------------------------------"
echo ""
git reset --hard
git pull
echo ""
echo "- Lunching data-analysis code -----------------------------------------"
echo ""
gdb --args clas12root -b -q ./main.c
echo ""
echo "- Operation finished --------------------------------------------------"
