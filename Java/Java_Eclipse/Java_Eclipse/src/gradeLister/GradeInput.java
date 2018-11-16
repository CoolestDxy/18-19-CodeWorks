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

	/**
	 * 从文件加载对象
	 * @param file 文件名
	 * @throws IOException
	 * @author Hanyuu
	 * @date 2018/11/17
	 */
	GradeInput(File file) throws IOException {
		if (!file.exists()) {
			throw new IOException("bad file access.");
		}
		input = new ObjectInputStream(new FileInputStream(file));
	}

	/**
	 * 释放资源
	 * @throws IOException
	 * @author Hanyuu
	 * @date 2018/11/17
	 */
	public void release() throws IOException {
		input.close();
	}

	/**
	 *  读取函数
	 * @return Object 返回对象
	 * @throws IOException
	 * @throws ClassNotFoundException
	 * @author Hanyuu
	 * @date 2018/11/17
	 */
	public Object read() throws IOException, ClassNotFoundException {
		return input.readObject();
	}
	public int hasNext() throws IOException{
		return input.available();
	}
}
