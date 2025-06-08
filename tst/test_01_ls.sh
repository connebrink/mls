#!/bin/bash
RED='\033[0;91m'
GREEN='\033[0;92m'
NC='\033[0m'

TEST_DIR="$1"
TEST_LS="ls $TEST_DIR"
TEST_MLS="$2 $TEST_DIR" 

OUTPUT_LS="$($TEST_LS)"
RETVAL_LS=$?
OUTPUT_MLS="$($TEST_MLS)"
RETVAL_MLS=$?

if [[ "$OUTPUT_LS" == "$OUTPUT_MLS" ]] && [ "$RETVAL_LS" -eq "$RETVAL_MLS" ]; then
    echo -e "    001 : ${GREEN}Passed${NC} : Simple run with given dir ($1)"
else
    echo -e "    001 : ${RED}Failed${NC} : Simple run with given dir ($1)"
fi
