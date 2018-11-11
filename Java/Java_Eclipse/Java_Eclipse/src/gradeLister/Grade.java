/**
 * @package gradeLister
 * @filename Grade.java
 * @author Hanyuu
 * @date 2018/54/11
 * @todo TODO
 */
package gradeLister;

import java.lang.Exception;

/**
 * @typename Grade
 * @package gradeLister
 * @description Grade
 * @author Hanyuu
 * @date 2018/11/11
 * @TODO TODO
 */
public class Grade implements java.io.Serializable{
	private String ID;
	private String name;
	private int grade;

	/**
	 * @return iD
	 */
	public String getID() {
		return ID;
	}

	/**
	 * @param iD iD
	 */
	public void setID(String iD) throws Exception {
		if (iD.length() != 8) {
			throw new Exception("the length of ID is invaild.");
		}
		ID = iD;
	}

	/**
	 * @return name
	 */
	public String getName() {
		return name;
	}

	/**
	 * @param name name
	 */
	public void setName(String name) throws Exception {
		if (name.length() > 5 || name.length() < 2) {
			throw new Exception("the length of name is invaild.");
		}

		this.name = name;
	}

	/**
	 * @return grade
	 */
	public int getGrade() {
		return grade;
	}

	/**
	 * @param grade grade
	 */
	public void setGrade(int grade) throws Exception {
		if (grade > 100 || grade < 0) {
			throw new Exception("grade invaild.");
		}
		this.grade = grade;
	}
}
