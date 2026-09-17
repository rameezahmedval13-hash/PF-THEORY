# PART B Question 5

### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Vehicle type (`vehicle_type`: 'C' for Car, 'B' for Bike, 'V' for Van)<br>• User category (`user_cat`: 'F' for Faculty, 'S' for Student, 'G' for Visitor)<br>• Permit status (`has_permit`: 'Y' or 'N')<br>• Emergency status (`is_emergency`: 'Y' or 'N' if no permit)<br>• Zone capacities (`capA`, `capB`, `capC`) | • Access status ("Approved" or "Rejected")<br>• Assigned parking zone (Zone A, B, or C)<br>• Updated capacity for the assigned zone<br>• Rejection reason (if access is denied) |
| **Processing Required** | **Solution Alternatives** |
| • Validate input options (`vehicle_type`, `user_cat`, `has_permit`).<br>• Check permit status; if 'N', prompt/check emergency status.<br>• Evaluate eligibility & space requirements:<br>&nbsp;&nbsp;– Faculty ('F'): Zone A (needs 1 space).<br>&nbsp;&nbsp;– Student ('S'): Cars/Bikes $\rightarrow$ Zone B (1 space); Vans $\rightarrow$ Redirect to Zone C (requires 2 spaces).<br>&nbsp;&nbsp;– Visitor ('G'): Cars/Bikes $\rightarrow$ Zone C (1 space); Vans $\rightarrow$ Zone C (requires 2 spaces).<br>• Update corresponding zone capacity if assigned. | 1. Implement complete batch processing using continuous loops for $N$ vehicles.<br>*2. Execute decision logic for a single vehicle entry request to evaluate authorization and zone allocation without repetition structures. |


### Input-Processing-Output (IPO) Chart

| Input | Processing | Module Reference | Output |
| :--- | :--- | :--- | :--- |
| • `vehicle_type` ('C', 'B', 'V')<br>• `user_cat` ('F', 'S', 'G')<br>• `has_permit` ('Y', 'N')<br>• `is_emergency` ('Y', 'N')<br>• `capA`, `capB`, `capC` | 1. Read `vehicle_type`, `user_cat`, `has_permit`<br>2. Validate input values; reject if invalid<br>3. If `has_permit == 'N'`, read `is_emergency`<br>4. If `has_permit == 'N'` AND `is_emergency == 'N'`, reject vehicle<br>5. Determine required zone and space requirement (1 or 2 spaces)<br>6. Check zone capacity availability<br>7. Deduct occupied space and assign zone OR display rejection reason<br>8. Display result and remaining capacity<br>9. End | Read<br>Selection<br>Read<br>Selection<br>Selection<br>Selection<br>Assign/Print<br>Print<br>CampusAccessControl | • Status message ("Approved" / "Rejected")<br>• Assigned Zone<br>• Rejection Reason (if applicable)<br>• Remaining Zone Capacity |

