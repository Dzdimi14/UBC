package arch.sm213.machine.student;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MainMemoryTest {
    private byte[] testMem;
    private MainMemory mm = new MainMemory(64);






    @Test
    public void isAccessAlignedTest() {
        assertEquals(true, mm.isAccessAligned(0, 4));
        assertEquals(true, mm.isAccessAligned(4, 4));
        assertEquals(true, mm.isAccessAligned(16,4));
        assertEquals(true, mm.isAccessAligned(16,8));
        assertEquals(true, mm.isAccessAligned(5, 1));

        assertEquals(false, mm.isAccessAligned(2,4));
        assertEquals(false, mm.isAccessAligned(3,4));
        assertEquals(false, mm.isAccessAligned(4,8));
    }

    @Test
    public void bytesToIntegerTest() {
        byte b0 = 0;
        byte b1 = 0;
        byte b2 = 0;
        byte b3 = 1;
        assertEquals(1, mm.bytesToInteger(b0, b1, b2, b3));
        assertEquals(16777216, mm.bytesToInteger(b3, b2, b1, b0));

    }

    @Test
    public void integerToBytesTest() {
        byte[] ret;
        ret = mm.integerToBytes(256);
        assertEquals(0x0, ret[0]);
        assertEquals(0x0, ret[1]);
        assertEquals(0x1, ret[2]);
        assertEquals(0x0, ret[3]);
    }


}
