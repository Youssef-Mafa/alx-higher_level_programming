#!/usr/bin/python3
""" displays the body of the response and handel error"""
import urllib.request
import urllib.parse
import sys
from urllib.error import HTTPError
if __name__ == "__main__":
    url = sys.argv[1]
    try:
        with urllib.request.urlopen(url) as response:
            contents_read = response.read()
            print(contents_read.decode('utf-8'))
    except HTTPError as e:
        print('Error code: {}'.format(e.code))
