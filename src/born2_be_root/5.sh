#sudo policy
sudo touch /etc/sudoers.d/sudo_config
sudo mkdir /var/log/sudo
su
sudo vim /etc/sudoers.d/sudo_config
###
#Defaults  passwd_tries=3
#Defaults  badpass_message="Mensaje de error personalizado"
#Defaults  logfile="/var/log/sudo/sudo_config"
#Defaults  log_input, log_output
#Defaults  iolog_dir="/var/log/sudo"
#Defaults  requiretty
#Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
###