if [ ! -f studentID.txt ]; then
	echo "Test User file not exits"
	exit 1
fi

usernames=$(cat studentID.txt)

for username in $usernames
do
	sudo chmod -R 700 /home/$username
done
