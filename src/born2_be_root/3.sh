#ssh
sudo apt update
sudo apt install openssh-server
sudo service ssh status
sudo apt install vim
su
vim /etc/ssh/sshd_config
#Port 22 -> Port 4242
#PermitRootLogin prohibit-password -> PermitRootLogin no
vim /etc/ssh/ssh_config
#Port 22 -> Port 4242
su -l xifeng # username
sudo service ssh restart
sudo service ssh status