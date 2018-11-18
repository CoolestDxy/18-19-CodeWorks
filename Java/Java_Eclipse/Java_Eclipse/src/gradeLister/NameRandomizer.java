/**
 * @package gradeLister
 * @filename NameRandomizer.java
 * @author Hanyuu
 * @date 2018/58/18
 * @todo TODO
 */
package gradeLister;
import java.util.ArrayList;
import java.util.Random;
/**
 * @typename NameRandomizer
 * @package gradeLister
 * @description NameRandomizer
 * @author Hanyuu
 * @date 2018/11/18
 * @TODO TODO
 */
public class NameRandomizer {
	private Random random ;
	public String[] firstname= {
			"Jacob","Michael","Joshua","Matthew","Andrew","Joseph","Nicholas","Anthony","Tyler","Daniel","Christopher","Alexander","John","William","Brandon","Dylan","Zachary","Ethan","Ryan","Justin","David","Benjamin","Christian","Austin","Cameron","James","Jonathan","Logan","Nathan","Samuel","Hunter","Noah","Robert","Jose","Thomas","Kyle","Kevin","Gabriel","Elijah","Jason","Luis","Aaron","Caleb","Connor","Luke","Jordan","Jack","Adam","Eric","Jackson","Carlos","Angel","Isaiah","Alex","Evan","Mason","Isaac","Jesus","Sean","Timothy","Patrick","Brian","Bryce","Nathaniel","Chase","Juan","Sebastian","Cole","Jared","Bryan","Garrett","Steven","Adrian","Cody","Charles","Devin","Eduardo","Richard","Marcus","Ian","Lucas","Seth","Xavier","Dalton","Jeremiah","Miguel","Blake","Edward","Wyatt","Fernando","Spencer","Antonio","Carson","Gavin","Julian","Oscar","Trevor","Tristan","Aidan","Dakota","Emily","Hannah","Madison","Samantha","Ashley","Sarah","Elizabeth","Kayla","Alexis","Abigail","Jessica","Taylor","Anna","Lauren","Megan","Brianna","Olivia","Victoria","Emma","Grace","Rachel","Jasmine","Nicole","Destiny","Alyssa","Chloe","Julia","Jennifer","Kaitlyn","Morgan","Isabella","Natalie","Alexandra","Sydney","Katherine","Amanda","Stephanie","Hailey","Maria","Gabrielle","Haley","Rebecca","Madeline","Sophia","Mary","Amber","Courtney","Jenna","Jordan","Sierra","Bailey","Mackenzie","Gabriella","Sara","Jada","Katelyn","Savannah","Kaylee","Allison","Andrea","Catherine","Danielle","Zoe","Alexa","Christina","Ariana","Caitlin","Michelle","Brooke","Kimberly","Makayla","Shelby","Trinity","Erin","Jade","Mariah","Melanie","Alexandria","Angela","Arianna","Jacqueline","Paige","Faith","Melissa","Riley","Vanessa","Ana","Isabel","Isabelle","Kelly","Marissa","Alexia","Angelica","Brittany","Jocelyn","Miranda","Mya","Caroline","Cassidy","Jordyn"
	}; 
	public String[] lastname= {
			"adams","anderson","arnold","baker","bell","campbell","carter","cecil","charles","christian","dale","david","clark","clive","cook","duncan","eddy","edward","evelyn","fergus","garcia","gary","george","gerard","giles","green","griffin","hall","harris","hill","jackson","james","ja","joyce","keith","kirk","lee","leonard","leslie","lester","lewis","may","murphy","nelson","oliver","owen","percy","peters","quick","raphael","rodney","rose","rupert","scott","shelley","smith","taylor","tuener","walker","warren","williams"	
	};
	NameRandomizer(){
		random=new Random(System.currentTimeMillis());
	}
	public  String getRandomName() {
		String fn=firstname[random.nextInt(firstname.length)];
		String ln=lastname[random.nextInt(lastname.length)];
		return fn+" "+ln;
	};
	public int getRandomScore() {
		return random.nextInt(101);
	}
	public String getRandomID() {
		String a=new String();
		for	(int i=0;i<8;i++) {
			a.concat(((Integer)random.nextInt(10)).toString());	
		}
		return a;
	}
}
