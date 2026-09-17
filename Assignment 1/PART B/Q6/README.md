# PART B Question 6

### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Vehicle type (`vehicle_type`: 'E' for Electric, 'H' for Hybrid)<br>• Current battery level (`soc` %)<br>• Required charging level (`req_level` %)<br>• Expected parking duration in hours (`duration`)<br>• Current time in 24-hr format (`time`)<br>• Parking membership (`is_member`: 'Y'/'N')<br>• Disabled-person priority (`is_disabled`: 'Y'/'N')<br>• Station availability (`station_avail`: 'Y'/'N') | • Vehicle type & battery percentages<br>• Charging priority category<br>• Peak / Off-peak time status<br>• Base charging cost & parking cost<br>• Total discount applied<br>• Final payable amount<br>• System messages & long-stay warnings |
| **Processing Required** | **Solution Alternatives** |
| • Check station availability & vehicle eligibility (`soc < 40` for Hybrids).<br>• `req_charging = req_level - soc` (if $\le 0$, no charging needed).<br>• Classify Priority:<br>&nbsp;&nbsp;– Priority 1 (Emergency): `soc <= 15` AND `req_level >= 80`<br>&nbsp;&nbsp;– Priority 2 (Priority Customer): (`is_disabled == 'Y'` OR `is_member == 'Y'`) AND `soc <= 30`<br>&nbsp;&nbsp;– Priority 3: Normal Charging<br>• Determine time status (Peak: 17:00 to 22:00, Off-peak: otherwise).<br>• Compute base charging cost (Off-peak: Rs. 35/unit, Peak: Rs. 50/unit).<br>• Compute charging discount (Member: 20% off-peak, 10% peak; 0% for Emergency).<br>• Compute parking cost (`duration` $\le 2$: 200, $\le 5$: 400, $> 5$: 700).<br>• Compute parking discount (Disabled: 100%, Member: 20%).<br>• `final_payable = charging_cost + parking_cost - total_discount`.<br>• Display long-stay warning if `duration > 8`. | 1. Calculate costs using fixed hardcoded inputs.<br>*2. Accept dynamic single-driver inputs to compute eligibility, priority, discounts, and final bill without loops. |


### Input-Processing-Output (IPO) Chart

| Input | Processing | Module Reference | Output |
| :--- | :--- | :--- | :--- |
| • `vehicle_type`<br>• `soc`<br>• `req_level`<br>• `duration`<br>• `time`<br>• `is_member`<br>• `is_disabled`<br>• `station_avail` | 1. Enter all input variables<br>2. Evaluate station availability & vehicle qualification<br>3. Compute `req_charging = req_level - soc`<br>4. Determine Priority (Emergency / Priority Customer / Normal)<br>5. Check Peak vs Off-Peak time status<br>6. Calculate base charging cost & charging discount<br>7. Calculate parking cost based on duration slab<br>8. Calculate parking discount (Disabled free, Member 20%)<br>9. Compute `final_payable = (charging_cost - charging_discount) + (parking_cost - parking_discount)`<br>10. Check duration warning (> 8 hours)<br>11. Print full summary and messages | Read<br>Selection<br>Calc<br>Selection<br>Selection<br>Calc/Selection<br>Selection<br>Selection<br>Calc<br>Selection<br>Print<br>EVManagementControl | • Vehicle summary<br>• Charging Priority<br>• Time Status<br>• Charging Cost<br>• Parking Cost<br>• Total Discount<br>• Final Payable Amount<br>• System Warnings |

