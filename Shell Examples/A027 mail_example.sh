#!/bin/bash
Recipient="admin@example.com"
Subject="Greeting"
Message="Welcome to our site"
`mail -s $Subject $Recipient <<< $Message

## It's possible to use both the 'mail' or 'sendmail' command.
## However, all necessary pacakges have to be installed beforehand.