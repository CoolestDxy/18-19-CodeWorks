/**
 * @package UI
 * @filename IUI_NestedLayout.java
 * @author Hanyuu
 * @date 2018/38/21
 * @todo TODO
 */
package UI;

import java.awt.*;
import javax.swing.*;

/**
 * @typename IUI_NestedLayout
 * @package UI
 * @description IUI_NestedLayout
 * @author Hanyuu
 * @date 2018/11/21
 * @TODO TODO
 */
public class UI_NestedLayout {
	private Component initLeft() {
		JPanel panelLeft = new JPanel();
		panelLeft.setLayout(new FlowLayout(FlowLayout.CENTER));
		panelLeft.add(new JButton("new"));
		panelLeft.add(new JButton("save"));
		panelLeft.add(new JButton("close"));
		panelLeft.add(new JButton("close"));
		panelLeft.add(new JButton("exit"));
		return panelLeft;
	}

	private Component initRight() {
		JPanel panelRight = new JPanel();
		panelRight.setLayout(new GridLayout(5, 1));
		JPanel panelTemp = null;
		for (int i = 0; i < 5; i++) {
			panelTemp = new JPanel();
			panelTemp.setLayout(new FlowLayout(FlowLayout.LEFT));
			panelTemp.add(new JLabel("Label" + i));
			panelTemp.add(new JTextField("TextField" + i));
			panelRight.add(panelTemp);
		}
		return panelRight;
	}

	public static void main(String[] args) {
		JFrame f = new JFrame("Hanyuu");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		UI_NestedLayout ne = new UI_NestedLayout();
		JSplitPane split = new JSplitPane();
		split.setLeftComponent(ne.initLeft());
		split.setRightComponent(ne.initRight());
		split.setDividerLocation(80);
		f.add(split);

		f.setSize(400,200);
		f.setVisible(true);
	}
}
