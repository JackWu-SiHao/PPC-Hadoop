if [ ! -f testID.txt ]; then
        echo "Test User file not exits"
        exit 1
fi

usernames=$(cat testID.txt)

for username in $usernames
do
        pass=$(mkpasswd -m SHA-512 $username)
        sudo useradd -m -s /bin/bash -g user $username -p $pass
        sudo chage -d 0 $username
done
