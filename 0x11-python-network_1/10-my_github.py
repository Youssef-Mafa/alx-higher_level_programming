#!/usr/bin/python3
'''display the id variable found in the header of the response'''
import requests
import sys

if __name__ == '__main__':

    r = requests.get('https://api.github.com/user',
                     auth=(sys.argv[1], sys.argv[2]))
    json = r.json()
    try:
        print(json['id'])
    except:
        print("None")
