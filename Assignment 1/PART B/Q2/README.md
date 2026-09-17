# PART B Question 2


### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Initial floor (`current_floor = 0`)<br>• Target floor request (`requested_floor`) | • Movement status message ("Moving Up", "Moving Down", or "Doors Opening")<br>• Updated `current_floor` value |
| **Processing Required** | **Solution Alternatives** |
| • Compare `requested_floor` with `current_floor` using decision logic:<br>&nbsp;&nbsp;– If `requested_floor > current_floor` → "Moving Up"<br>&nbsp;&nbsp;– If `requested_floor < current_floor` → "Moving Down"<br>&nbsp;&nbsp;– If `requested_floor == current_floor` → "Doors Opening"<br>• Set `current_floor = requested_floor` | 1. Hardcode `current_floor` and `requested_floor` directly as fixed variables.<br>*2. Input `requested_floor` dynamically and process the state change for a single execution. |


### Input-Processing-Output (IPO) Chart

| Input | Processing | Module Reference | Output |
| :--- | :--- | :--- | :--- |
| • Current floor (`current_floor`)<br>• Requested floor (`requested_floor`) | 1. Initialize `current_floor = 0`<br>2. Enter `requested_floor`<br>3. Compare `requested_floor` with `current_floor`<br>4. Print status message ("Moving Up", "Moving Down", or "Doors Opening")<br>5. Update `current_floor = requested_floor`<br>6. Display updated `current_floor`<br>7. End | Initialize<br>Read<br>Selection<br>Print<br>Assign<br>Print<br>ElevatorControl | • Direction status message<br>• Updated `current_floor` |
