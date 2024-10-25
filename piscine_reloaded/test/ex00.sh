rm -rf ../ex00
mkdir ../ex00
cd ../ex00
mkdir test0
touch test1
mkdir test2
touch test3
touch test4
echo sss >> test1
printf "s" >> test3
echo s >> test4
ln test3 test5
ln -s test0 test6
chmod 715 test0
chmod 714 test1
chmod 504 test2
chmod 404 test3
chmod 641 test4
touch -mht '2406012047' test0
touch -mht '2406012146' test1
touch -mht '2406012245' test2
touch -mht '2406012344' test3
touch -mht '2406012343' test4
touch -mht '2406012344' test5
touch -mht '2406012220' test6
tar -cf exo.tar *