# PART B Question 2


### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Initial floor (`current_floor = 0`)<br>• Number of requests (`N`)<br>• Target floor per request (`requested_floor`) | • Status message per request ("Moving Up", "Moving Down", or "Doors Opening")<br>• Updated `current_floor` position after each request |
| **Processing Required** | **Solution Alternatives** |
| • Loop `N` times to process each request sequentially.<br>• Compare `requested_floor` with `current_floor` using decision logic:<br>&nbsp;&nbsp;– If `requested_floor > current_floor` → "Moving Up"<br>&nbsp;&nbsp;– If `requested_floor < current_floor` → "Moving Down"<br>&nbsp;&nbsp;– If `requested_floor == current_floor` → "Doors Opening"<br>• Set `current_floor = requested_floor` after each stop. | 1. Store all floor requests in an array and iterate using a loop.<br>*2. Input each requested floor interactively inside a loop and update state dynamically. |


### Input-Processing-Output (IPO) Chart

| Input | Processing | Module Reference | Output |
| :--- | :--- | :--- | :--- |
| • Total floor requests (`N`)<br>• Target floor (`requested_floor`) | 1. Initialize `current_floor = 0`<br>2. Read total requests (`N`)<br>3. Loop `i` from 1 to `N`<br>4. Read `requested_floor`<br>5. Compare `requested_floor` with `current_floor`<br>6. Print status message ("Moving Up", "Moving Down", or "Doors Opening")<br>7. Update `current_floor = requested_floor`<br>8. End Loop<br>9. End | Initialize<br>Read<br>Loop<br>Read<br>Selection<br>Print<br>Assign<br>Loop<br>ElevatorControl | • Direction status message per request ("Moving Up" / "Moving Down" / "Doors Opening") |
