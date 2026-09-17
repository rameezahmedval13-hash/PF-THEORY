# PART B Question 4

### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Quantity purchased (`q`)<br>• Price per item (`p`)<br>• Discount percentage (`d`)<br>• Tax percentage (`t`)<br>• Mathematical formulas:<br>&nbsp;&nbsp;– Subtotal: $s = q \times p$<br>&nbsp;&nbsp;– Discounted Amount: $a = s - (s \times d) / 100$<br>&nbsp;&nbsp;– Final Bill: $f = a + (a \times t) / 100$ | • Subtotal (`s`)<br>• Discounted Amount (`a`)<br>• Final Bill (`f`)<br>• Error message (if inputs are invalid) |
| **Processing Required** | **Solution Alternatives** |
| • Validate inputs ($q > 0$, $p \ge 0$, $d \ge 0$, $t \ge 0$).<br>• If invalid, display an error message and terminate calculation.<br>• Else execute formulas sequentially:<br>&nbsp;&nbsp;1. $s = q \times p$<br>&nbsp;&nbsp;2. $a = s - (s \times d) / 100$<br>&nbsp;&nbsp;3. $f = a + (a \times t) / 100$<br>• Print bill details. | 1. Calculate final bill without validating inputs, potentially producing invalid prices.<br>*2. Validate inputs before performing calculations and abort on invalid data. |


### Input-Processing-Output (IPO) Chart

| Input | Processing | Module Reference | Output |
| :--- | :--- | :--- | :--- |
| • Quantity (`q`)<br>• Price per item (`p`)<br>• Discount % (`d`)<br>• Tax % (`t`) | 1. Read `q`, `p`, `d`, `t`<br>2. Check if $q \le 0$ OR $p < 0$ OR $d < 0$ OR $t < 0$<br>3. If invalid, display "Error: Invalid Input" and stop<br>4. Calculate `s = q * p`<br>5. Calculate `a = s - (s * d) / 100`<br>6. Calculate `f = a + (a * t) / 100`<br>7. Print `s`, `a`, and `f`<br>8. End | Read<br>Selection<br>Print<br>Calc<br>Calc<br>Calc<br>Print<br>BillCalculatorControl | • Error message (if invalid input)<br>• Subtotal (`s`)<br>• Discounted Amount (`a`)<br>• Final Bill (`f`) |

