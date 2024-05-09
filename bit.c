#include <stdio.h>

// unsigned int BitMapCounter (unsigned int BitMap) {
//     unsigned int i;
//     unsigned int Count;
//     unsigned int temp = 0;

//     Count = 0;
//     for (i = 0; i < 32; i++)  {
//         if (BitMap & (1 << i))  {
//         Count++;

//         temp = temp | (1 <<i);
//         }

//         if (temp == BitMap) {
//         break;
//         }
//     }

//     return Count;

// }

// unsigned int BitMapCounter (unsigned int BitMap)    {
//     unsigned int count = 0;
//     while (BitMap)  {
//         count += BitMap & 1;
//         BitMap >>= 1;
//     }

//     return count;
// }

unsigned int BitMapCounter (unsigned int BitMap) {
    unsigned int count = 0;

    while (BitMap)  {
        BitMap = BitMap & (BitMap - 1);
        count++;
    }

    return count;
}

int main() {

	/*
    unsigned int BitMap = 0x7030;
    unsigned int EnabledCount = 0;

    EnabledCount = BitMapCounter (BitMap);
    printf ("%X has %d of enabled bits\n", BitMap, EnabledCount);

    BitMap = 0x1;
    EnabledCount = BitMapCounter (BitMap);
    printf ("%X has %d of enabled bits\n", BitMap, EnabledCount);

    BitMap = 0x8;
    EnabledCount = BitMapCounter (BitMap);
    printf ("%X has %d of enabled bits\n", BitMap, EnabledCount);

    BitMap = 0x7;
    EnabledCount = BitMapCounter (BitMap);
    printf ("%X has %d of enabled bits\n", BitMap, EnabledCount);
	*/

	// Bit mask shortcuts
	char u_char = 'U';
	char l_char = 'l';

	printf ("to_lower: %c\n", u_char | ' ');
	printf ("to_upper: %c\n", l_char & '_');

	// Clear all other bits except the lowest set bit
	unsigned int low_bit = 5;
	printf ("only_low_bit: %u\n", low_bit & ~(low_bit - 1));		// 101 --> ans = 1

	// clear all lower bits till ith position
	unsigned int no = 5;
	int i = 2;				// ==> ans = 4
	unsigned int mask_no = ~((1 << i) - 1);
	printf ("clear_low: %u\n", no & mask_no);

	// clear all bits from MSB to ith position
	unsigned m_no = 7;
	unsigned int mask_msb = (1 << i) - 1;
	printf ("clear_high: %u\n", m_no & mask_msb);				// ans = 3;

	// log of a num;
	int num_log = 31;
	int log = 0;
	while (num_log >>= 1)
		log++;
	printf ("log: %d\n", log);

	// power of 2
	int power2 = 15;

	printf ("power2: %d\n", !(power2 & power2-1));

	int usign = -34;

	printf ("usign * 2: %d\n", usign << 4);

	int arr[10];
	int *p = arr;

	printf ("sizeof(arr): %d\tsizeof(*p): %d\n", sizeof(arr), sizeof(*p));


    return 0;
}
