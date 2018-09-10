#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "USAGE: comptract.sh <ACCOUNT NAME> <Contract Name> from within the directory"
    exit 1
fi

ACCOUNT=$1
CONTRACT=$2

eosiocpp -o ${CONTRACT}.wast ${CONTRACT}.cpp && 
eosiocpp -g ${CONTRACT}.abi ${CONTRACT}.cpp 
#&&
#cleos set contract ${ACCOUNT} ../${CONTRACT}
