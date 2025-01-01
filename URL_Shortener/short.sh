#!/bin/bash
echo -e "\e[32;1m" 

figlet "URL Shortener"

echo -e "\e[0m"

if [ -z "$1" ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

long_url=$1
encoded_url=$(echo "$long_url" | jq -sRr @uri)
short_url=$(curl -s "https://is.gd/create.php?format=simple&url=$encoded_url")

if [[ $short_url == "Error:"* ]]; then
    echo -e "\e[31mFailed to shorten URL. Please check the input URL.\e[0m"
else
     echo -e "Shortened URL:\e[32m $short_url\e[0m"
fi

