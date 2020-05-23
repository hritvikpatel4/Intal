#!/bin/bash

gcc intal.c intal_test.c
/usr/bin/time -v ./a.out
rm -rf a.out
