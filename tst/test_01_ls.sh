#!/bin/bash
RED='\033[0;91m'
GREEN='\033[0;92m'
NC='\033[0m'

TEST_DIR="$1"
TEST_LS="ls $TEST_DIR"
TEST_MLS="$2 $TEST_DIR" 

OUTPUT_LS="$($TEST_LS)"
OUTPUT_MLS="$($TEST_MLS)"

if [[ "$OUTPUT_LS" == "OUTPUT_MLS" ]]; then
    echo -e "test_01 : ${GREEN}Passed${NC}"
    exit 0
else
    echo -e "test_01 : ${RED}Failed${NC}"
    exit 0
fi
