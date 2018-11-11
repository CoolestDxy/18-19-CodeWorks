/**
 * @package gradeLister
 * @filename GradeOutput.java
 * @author Hanyuu
 * @date 2018/53/11
 * @todo TODO
 */
package gradeLister;

import java.io.File;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;
import java.lang.ClassNotFoundException;
/**
 * @typename GradeOutput
 * @package gradeLister
 * @description GradeOutput
 * @author Hanyuu
 * @date 2018/11/11
 * @TODO TODO
 */
public class GradeOutput{
	ObjectOutputStream output;
	/**
	 * @param file
	 * @throws IOException
	 * @author Hanyuu
	 * @date 2018/11/11
	 */
	GradeOutput(File file)throws IOException{
		file.createNewFile();
		output=new ObjectOutputStream(new FileOutputStream(file));
	}
	/**
	 * @throws IOException
	 * @author Hanyuu
	 * @date 2018/11/11
	 */
	public void release() throws IOException{
		output.close();
	}
	public void write(Grade grade)throws IOException{
		output.writeObject(grade);
	}

}
