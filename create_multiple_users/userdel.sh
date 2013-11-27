if [ ! -f testID.txt ]; then
        echo "Test User file not exits"
        exit 1
fi

usernames=$(cat testID.txt)

for username in $usernames
do
        sudo userdel -r $username
done
