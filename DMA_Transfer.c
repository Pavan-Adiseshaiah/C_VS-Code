/**
 * DMA Transfer (Tx)
 *
 * We have a network interface ASIC that can DMA packets directly to/from our
 * RAM to/from the Ethernet. It is controlled by 4 memory mapped registers all
 * 4 bytes (one word) wide (see registers map below). The block can be accessed
 * from 0xd000000.
 *
 * The first register is the control register and is at offset 0x0.
 *   - Bit 0 controls the direction of the transfer (1=Tx, 0=Rx).
 *   - Bit 1 is the Go bit, setting it to 1 sets the DMA controller into
 *     action, either DMA’ing data from our memory out onto the Ethernet or
 *     ready to DMA data from the Ethernet into our memory and the specified
 *     address.
 *   - Bit 31 is the reset bit. Setting it to 1 causes the controller to reset
 *     to a known state (i.e. ready to go). The bit will be cleared when reset
 *     iscomplete.
 *
 * The second register is at offset 0x4 and is the address register. Write the
 * RAM address here for the location of a buffer to be transferred out or ready
 * to have data transferred into.
 *
 * The third register is at offset 0x8 and is the length register. Program the
 * length of data to transfer out of our memory (Tx) or the size of the buffer
 * available to receive data from the Ethernet.
 *
 * The forth register at offset 0xc is the status register.
 *   - Bits 0:3 contain the status of the transfer where 0 indicates a
 *     successful transfer and non-zero indicates some form of error. The exact
 *     codes are not important for the context of this question.
 *   - Bit 31 contains the complete bit. It will be set to 1 when the transfer
 *     completes. It is automatically cleared when the Go bit in the Control
 *     register is set to begin a transfer.
 */
 
 #define TX             0x01
 #define RX             0x00
 #define SET_GO         0x10
 #define RESET_GO       0x00
 #define RESET          0x80000000
 #define IS_COMPLETE    0x80000000
 #define STATUS_CHECK   0x0F
 
int dmaTx(char *buffer, int len) {
    unsigned int *control_reg = 0x000000;
    unsigned int *addr_reg = 0x04;
    unsigned int *len_reg = 0x08;
    unsigned int *status_reg = 0x0c;
    
    *control_reg |= RESET;
    *control_reg &= ~RESET;          // Clear the reset bit
    *control_reg |= TX;             // TX
    
    
    *addr_reg = (unsigned int *) buffer;
    *len_reg = (unsigned int) len;
    *control_reg |= SET_GO;
    
    while (!(*status_reg & IS_COMPLETE));
    
    switch (*status_reg & STATUS_CHECK) {
        case 0: default:
            printf ("Transferred successfully\n");
            break;
        case 1: case 2: case 3:
            perror ("Error in Transfer!\n");
            return (*status_reg & STATUS_CHECK);
    }
    
    return 0;
    
}
