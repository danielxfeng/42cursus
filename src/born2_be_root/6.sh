vim /etc/login.defs

#PASS_MAX_DAYS 30
#PASS_MIN_DAYS 2
#PASS_WARN_AGE 7
sudo apt install libpam-pwquality
vim /etc/pam.d/common-password

// minlen=10
//ucredit=-1
//dcredit=-1
//lcredit=-1
//maxrepeat=3
//reject_username
//difok=7
//enforce_for_root

sudo chage -l xifeng
sudo chage -l root
sudo chage -m 2 xifeng
sudo chage -m 2 root
sudo chage -M 30 xifeng
sudo chage -M 30 root