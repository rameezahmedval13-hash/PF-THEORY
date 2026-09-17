#PART B Question 1

### Algorithm

1. **START**
2. Read `season` (1 for Peak, 2 for Off-Peak), `room_type` (1 for Standard, 2 for Deluxe, 3 for Suite), and `nights`.
3. **IF** `season == 1` (Peak):
   - **IF** `room_type == 1` THEN `rate = 5000`
   - **ELSE IF** `room_type == 2` THEN `rate = 8000`
   - **ELSE IF** `room_type == 3` THEN `rate = 12000`
4. **ELSE IF** `season == 2` (Off-Peak):
   - **IF** `room_type == 1` THEN `rate = 3000`
   - **ELSE IF** `room_type == 2` THEN `rate = 5000`
   - **ELSE IF** `room_type == 3` THEN `rate = 8000`
5. Calculate `base_total = rate * nights`.
6. **IF** `nights > 7` THEN:
   - `discount = base_total * 0.15`
   **ELSE**:
   - `discount = 0.0`
7. Calculate `final_price = base_total - discount`.
8. Print `final_price`.
9. **END**

### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Season (`season`: 1 for Peak, 2 for Off-Peak)<br>• Room type (`room_type`: 1 for Standard, 2 for Deluxe, 3 for Suite)<br>• Nights stayed (`nights`)<br>• Rate schedule (Peak: 5k/8k/12k, Off-Peak: 3k/5k/8k)<br>• Flat 15% discount rule for `nights > 7` | • Final bill for the guest (`final_price`) |
| **Processing Required** | **Solution Alternatives** |
| • Determine `rate` using nested decision logic on `season` and `room_type`<br>• `base_total = rate * nights`<br>• If `nights > 7`, `discount = base_total * 0.15`, else `discount = 0.0`<br>• `final_price = base_total - discount` | 1. Hardcode fixed input values inside the program to calculate the bill.<br>*2. Accept dynamic input values from the user to calculate the bill. |

### Input-Processing-Output (IPO) Chart

| Input | Processing | Module Reference | Output |
| :--- | :--- | :--- | :--- |
| • Season (`season`)<br>• Room type (`room_type`)<br>• Nights stayed (`nights`) | 1. Enter `season`, `room_type`, `nights`<br>2. Determine `rate` via season & room type<br>3. Calculate `base_total = rate * nights`<br>4. Calculate `discount` if `nights > 7`<br>5. Calculate `final_price = base_total - discount`<br>6. Print `final_price`<br>7. End | Read<br>Selection<br>Calc<br>Selection<br>Calc<br>Print<br>HotelBookingControl | • Guest final price (`final_price`) |
