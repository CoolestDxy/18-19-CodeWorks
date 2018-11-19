/**
 * @package UI
 * @filename uiPractice.java
 * @author Hanyuu
 * @date 2018/06/19
 * @todo TODO
 */
package UI;

import javax.swing.*;

/**
 * @typename uiPractice
 * @package UI
 * @description uiPractice
 * @author Hanyuu
 * @date 2018/11/19
 * @TODO TODO
 */
public class uiPractice extends JFrame {
//	JTextArea txa=new JTextArea();
	public uiPractice() {
		JTextArea txa = new JTextArea();
		TextSelectionPanel panel = new TextSelectionPanel();
		this.setTitle("Hanyuu");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.add(txa);
		this.add(panel);
		this.setSize(600,200);
	}
	public static void main(String[] args) {
		uiPractice ui=new uiPractice();
		ui.setVisible(true);
	}
}