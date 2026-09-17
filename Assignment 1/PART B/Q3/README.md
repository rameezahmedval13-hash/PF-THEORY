# PART B Question 3

### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Marks for 5 subjects (`m1, m2, m3, m4, m5`) out of 100<br>• Passing threshold per subject (33)<br>• Average criteria: Distinction ($\ge 80$), Pass ($60 - 79$), Fail ($< 60$) | • Student average mark (`average`)<br>• Final result classification (`result`) |
| **Processing Required** | **Solution Alternatives** |
| • `sum = m1 + m2 + m3 + m4 + m5`<br>• `average = sum / 5.0`<br>• Check if any subject mark is below 33:<br>&nbsp;&nbsp;– If `m1 < 33 OR m2 < 33 OR m3 < 33 OR m4 < 33 OR m5 < 33` → Override `result = "Fail — Subject Deficiency"`<br>• Else evaluate `average`:<br>&nbsp;&nbsp;– If `average >= 80` → `result = "Distinction"`<br>&nbsp;&nbsp;– Else if `average >= 60` → `result = "Pass"`<br>&nbsp;&nbsp;– Else → `result = "Fail"` | 1. Use hardcoded subject marks for a single test run.<br>*2. Accept dynamic inputs for 5 subject marks to compute average and determine status via conditional logic without loops. |

### Input-Processing-Output (IPO) Chart

| Input | Processing | Module Reference | Output |
| :--- | :--- | :--- | :--- |
| • Subject 1 mark (`m1`)<br>• Subject 2 mark (`m2`)<br>• Subject 3 mark (`m3`)<br>• Subject 4 mark (`m4`)<br>• Subject 5 mark (`m5`) | 1. Enter `m1, m2, m3, m4, m5`<br>2. Compute `sum = m1 + m2 + m3 + m4 + m5`<br>3. Compute `average = sum / 5.0`<br>4. Check if any `m < 33` for subject deficiency override<br>5. If no deficiency, classify `result` based on `average`<br>6. Display `average` and `result`<br>7. End | Read<br>Calc<br>Calc<br>Selection<br>Selection<br>Print<br>ClassResultControl | • `average`<br>• `result` ("Distinction", "Pass", "Fail", or "Fail — Subject Deficiency") |
