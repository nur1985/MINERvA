#!/bin/sh
#################################################################
# A shell script for MINERvA 101 systematic tutorial 
# Nuruzzaman <nur@fnal.gov>, Date Created: 06/07/2016
# 
#################################################################
LAST_MODIFIED="06/21/2016"

set -P
export User_release_area="/minerva/app/users/$USER/cmtuser"

SOFTWARE_VERSION="v10r8p9"
SYS_PACAKAGE="v10r8p9_minerva101_2016"
SYS_PACAKAGE_FOLDER="Minerva_v10r8p9_minerva101_2016"

everything() {
# enviroment setup for the minerva software
    echo "using $SOFTWARE_VERSION"
    source /grid/fermiapp/minerva/software_releases/$SOFTWARE_VERSION/setup.sh 
    setenvMinerva $SYS_PACAKAGE

if [ ! -d "Ana/PlotUtils" ]; then
  echo "This is your first time calling this userSetup script. It will edit the cmt project file and checkout the head of PlotUtils..."

    cd cmt
    rm -f project.cmt
    echo "project MINERVA_$SOFTWARE_VERSION" >> project.cmt
    echo "use MINERVA MINERVA_$SOFTWARE_VERSION" >> project.cmt

    setenvMinerva $SYS_PACAKAGE >> /dev/null 2>&1

    echo cvs co Ana/PlotUtils
    cvs co Ana/PlotUtils >> /dev/null 2>&1
    cd Ana/PlotUtils/cmt
    cmt config >> /dev/null 2>&1
    echo "The compilation may take some minutes.. hang in there!"
    make >> /dev/null 2>&1
    echo "PlotUtils checked out and compiled!"
    source $User_release_area/$SYS_PACAKAGE_FOLDER/Ana/PlotUtils/cmt/setup.sh
    scp  $User_release_area/$SYS_PACAKAGE_FOLDER/Ana/PlotUtils/setup/.rootlogon.C ~
    scp  $User_release_area/$SYS_PACAKAGE_FOLDER/Ana/PlotUtils/setup/.rootrc ~
  
fi

    setenvMinerva $SYS_PACAKAGE >> /dev/null 2>&1

if [ ! -d "Ana/UnfoldUtils" ]; then
  echo "It will now checkout the head of UnfoldUtils..."

    setenvMinerva $SYS_PACAKAGE >> /dev/null 2>&1

    echo cvs co Ana/UnfoldUtils
    cvs co Ana/UnfoldUtils >> /dev/null 2>&1
    cd Ana/UnfoldUtils/cmt
    cmt config >> /dev/null 2>&1
    echo "The compilation may take some minutes.. hang in there!"
    make >> /dev/null 2>&1
    echo "UnfoldUtils checked out and compiled!"
    source $User_release_area/$SYS_PACAKAGE_FOLDER/Ana/UnfoldUtils/cmt/setup.sh

fi

source $User_release_area/$SYS_PACAKAGE_FOLDER/Ana/PlotUtils/cmt/setup.sh
source $User_release_area/$SYS_PACAKAGE_FOLDER/Ana/UnfoldUtils/cmt/setup.sh

echo cd $User_release_area/$SYS_PACAKAGE_FOLDER/
cd $User_release_area/$SYS_PACAKAGE_FOLDER/

if [ ! -d "/SystematicsActivity2016" ]; then
   echo "Copying the template files"

   echo scp -r /minerva/data/users/Minerva101/SystematicsActivity2016/ .
   scp -r /minerva/data/users/Minerva101/SystematicsActivity2016/ .

fi


echo "User release area:" $User_release_area
pwd   
}

help_function() {
clear
echo -e "---------------------------------------------------------------------------"
echo -e "|                     MINERvA Systematic Activity                         |"
echo -e "---------------------------------------------------------------------------"
echo -e "source $(basename $BASH_SOURCE) [option]"
echo -e ""
echo -e "${underline}[option]${normal}\t${underline}Function${normal}"
echo -e "all\t\tset enviornment and get packages for the systematic activities"
echo -e "solution\tget solutions for the activities"
echo -e "final\t\tget compiled and final solution for the systematic activities"
echo -e "help\t\tget this help message"
echo -e "---------------------------------------------------------------------------"
}

solution() {
   echo scp /minerva/data/users/Minerva101/SystematicsActivity2016Final/Systematics_Solution*.cxx $User_release_area/$SYS_PACAKAGE_FOLDER/SystematicsActivity2016
   scp /minerva/data/users/Minerva101/SystematicsActivity2016Final/Systematics_Solution*.cxx $User_release_area/$SYS_PACAKAGE_FOLDER/SystematicsActivity2016
   echo -e "Solutions are copied now."
}

final() {
   echo scp /minerva/data/users/Minerva101/SystematicsActivity2016Final/* $User_release_area/$SYS_PACAKAGE_FOLDER/SystematicsActivity2016/
   scp /minerva/data/users/Minerva101/SystematicsActivity2016Final/* $User_release_area/$SYS_PACAKAGE_FOLDER/SystematicsActivity2016/*
   echo -e "Final version of solutions are copied."
}


case "$1" in
  "help" | "-help" | "--help" | "h" | "-h" | "usage" | "$nullVariable" )
    help_function  # calling function help()
    ;;
  all)
    everything  # calling function everything()
    ;;
  solution)
    solution  # calling function solution()
    ;;
  final)
    final  # calling function final()
    ;;
  *)
esac

# check if project minerva was setted
#if [ ! -d $User_release_area/Minerva_$MINERVA_RELEASE ]; then
#echo "Setting Minerva project in: " $User_release_area
#setenvMinerva $MINERVA_RELEASE
#fi
