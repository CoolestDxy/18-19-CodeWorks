/**
 * @package UI
 * @filename UI_GridFrame.java
 * @author Hanyuu
 * @date 2018/01/21
 * @todo TODO
 */
package UI;

import javax.swing.*;
import java.awt.*;

/**
 * @typename UI_GridFrame
 * @package UI
 * @description UI_GridFrame
 * @author Hanyuu
 * @date 2018/11/21
 * @TODO TODO
 */
public class UI_GridFrame {
	JFrame frame;
	public UI_GridFrame() {
		frame=new JFrame();
		frame.setLayout(new GridLayout(3,3));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JButton []button = new JButton[9];
		for	(int i=0;i<9;i++) {
			button[i]=new JButton();
			frame.add(button[i]);
		}
		frame.setSize(300,300);
		frame.setVisible(true);
	}
	public static void main(String[] args) {
		UI_GridFrame a=new UI_GridFrame();
	}
}
