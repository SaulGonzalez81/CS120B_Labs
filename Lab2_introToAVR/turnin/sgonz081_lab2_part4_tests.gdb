# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x00, PINB: 0x00 PINC: 0x00 => PORTD: 0"
# Set inputs
setPINA 0x00
setPINB 0x00
setPINC 0x00
# Continue for several ticks
continue 2
# Set expect values
expectPORTD 0
# Check pass/fail
checkResult

# Add tests below

test "PINA : 0x6F, PINB : 0x0E, PINC : 0x32 => PORTD: 0xAD"
setPINA 0x6F
setPINB 0x0E
setPINC 0x32
continue 2
expectPORTD 0xAD
checkResult

test "PINA : 0x0C, PINB : 0x00, PINC : 0x00 => PORTD: 0x0C"
setPINA 0x0C
setPINB 0x00
setPINC 0x00
continue 2
expectPORTD 0x0C
checkResult

test "PINA: 0x00, PINB : 0x12, PINC : 0x50 => PORTD: 0x60"
setPINA 0x00
setPINB 0x12
setPINC 0x50
continue 2
expectPORTD 0x60
checkResult

#test "PINA : 0x0C, PINB : 0x00, PINC : 0x62 => PORTD: 0x6E"
#setPINA 0x0C
#setPINB 0x00
#setPINC 0x62
#continue 2
#expectPORTD 0x6E
#checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n

