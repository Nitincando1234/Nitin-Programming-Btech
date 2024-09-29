echo "Updating Repositories "
sudo apt update
echo "Upgrading Packages "
sudo apt upgrade

sleep 1

printf "Want to Install the Ubuntu Desktop:(y/n) "
read choice
if [ "$choice" = 'y' ];
then
echo "Installing Ubuntu Desktop"
sudo apt install ubuntu-desktop -y
else
echo "Skipping Ubuntu Desktop GUI installation"
fi

sleep 1
echo "Installing Chrome remote Desktop"
wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i google-chrome-stable_current_amd64.deb

wget https://dl.google.com/linux/direct/chrome-remote-desktop_current_amd64.deb
sudo dpkg -i chrome-remote-desktop_current_amd64.deb

sudo apt --fix-broken install -y

rm -f chrome-remote-desktop_current_amd64.deb
rm -f google-chrome-stable_current_amd64.deb
echo "Installed Chrome Remote Desktop Successfully \nPlease setup using ssh later this script execution completes."

sleep 1

echo "Installing XRDP"
sudo apt install xrdp -y 
echo "Installing PulseAudio\n"
sudo apt install pulseaudio-module-xrdp -y
echo "Configuring xrdp to use PulseAudio..."
sudo nano /etc/xrdp/xrdp.ini
sudo bash -c 'cat << EOF >> /etc/xrdp/xrdp.ini

[Xorg]
...
# Add or uncomment the following line
xrdp.ini = /etc/xrdp/xrdp.ini
EOF'

pulseaudio -k
pulseaudio --start

echo "Configuring PulseAudio for network access..."
sudo bash -c 'cat << EOF >> /etc/pulse/default.pa
load-module module-native-protocol-tcp auth-ip-acl=127.0.0.1
EOF'

pulseaudio -k
pulseaudio --start

echo "Configuring Firewall\n"
sudo ufw allow 3389/tcp

sleep 1

printf "Want to Install the Android Studio:(y/n) "
read choice
if [ "$choice" = 'y' ];
then
echo "Installing Android Studio"
sudo snap install android-studio --classic
else
echo "Skipping Android Studio installation"
fi

sleep 1
echo "Installing Git"
sudo apt install git git-lfs -y
echo "Git Installed"

echo "Adding your default Github (Nitincando1234/Android-Dev) directory..."
printf "Provide your Github Token: "
read token
echo "The link is: https://${token}@github.com/Nitincando1234/Android-Dev.git"
git clone https://$token@github.com/Nitincando1234/Android-Dev.git
mv Android-Dev ~/Downloads/

sleep 1

printf "Want to Install the Steam:(y/n) "
read choice
if [ "$choice" = 'y' ];
then
echo "Installing Steam"
sudo snap install steam
else
echo "Skipping Steam installation"
fi

sleep 1
echo "Setting the FHD resolution\n"
xrandr --newmode "1920x1080_60.00"  173.00  1920 2048 2248 2576  1080 1083 1088 1120 -hsync +vsync
xrandr --addmode screen "1920x1080_60.00"
xrandr --output screen --mode "1920x1080_60.00"

sleep 1

printf "Want to Install the wine:(y/n) "
read choice
if [ "$choice" = 'y' ];
then
echo "Installing Wine"
sudo dpkg --add-architecture i386
sudo mkdir -pm755 /etc/apt/keyrings
sudo wget -O /etc/apt/keyrings/winehq-archive.key https://dl.winehq.org/wine-builds/winehq.key
sudo wget -NP /etc/apt/sources.list.d/ https://dl.winehq.org/wine-builds/ubuntu/dists/$(lsb_release -cs)/winehq-$(lsb_release -cs).sources
sudo apt update
sudo apt install --install-recommends winehq-stable
winecfg

else
echo "Skipping wine installation"
fi

if [ $? -eq 0 ];
then echo "Some Error Occured !"
else 
echo "OK !"
fi

