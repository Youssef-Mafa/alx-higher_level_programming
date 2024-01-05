#!/bin/bash
# URL as an argument, sends a GET request to the URL
curl -s "$1" -X POST -d "email=test@gmail.com&subject=I will always be here for PLD"
