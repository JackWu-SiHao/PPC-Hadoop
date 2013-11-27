if [ ! -f testID.txt ]; then
        echo "Test User file not exits"
        exit 1
fi

usernames=$(cat testID.txt)

for username in $usernames
do
	echo "userdel -r $username"
        sudo userdel -r $username
done
