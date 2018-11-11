/**
 * @package gradeLister
 * @filename GradeInput.java
 * @author Hanyuu
 * @date 2018/53/11
 * @todo TODO
 */
package gradeLister;

import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.io.IOException;
import java.lang.ClassNotFoundException;
//import java.io.*;

/**
 * @typename GradeInput
 * @package gradeLister
 * @description GradeInput
 * @author Hanyuu
 * @date 2018/11/11
 * @TODO TODO
 */

public class GradeInput {
	ObjectInputStream input;

	GradeInput(File file) throws IOException {
		if (!file.exists()) {
			throw new IOException("bad file access.");
		}
		input = new ObjectInputStream(new FileInputStream(file));
	}

	/**
	 * @throws IOException
	 * @author Hanyuu
	 * @date 2018/11/11
	 */
	public void release() throws IOException {
		input.close();
	}

	/**
	 * 
	 * @author Hanyuu
	 * @date 2018/11/11
	 */
	public Grade read() throws IOException, ClassNotFoundException {
		return (Grade) input.readObject();
	}
	public int hasNext() throws IOException{
		return input.available();
	}
}
