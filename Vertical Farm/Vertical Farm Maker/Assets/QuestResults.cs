using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class QuestResults : MonoBehaviour
{

    public static float Volume;
    public static float LandPrice;
    public static float initCost;
    public static float yearlyCost;
    public static float yearlyGain;  
    public static float years = 1f;
    public string size;

    private Text text;

    // Start is called before the first frame update
    void Awake()
    {
        text = GetComponent<Text>();
        if (Volume < 2000)
        {
            size = "Small";
        }
        if (Volume >= 2000 && Volume < 45000)
        {
            size = "Medium";
        }
        if (Volume >= 45000)
        {
            size = "Large";
        }
        float totalGain = yearlyGain;
        if(totalGain > 1)
        {
            while (totalGain < initCost)
            {
                totalGain = totalGain + yearlyGain;
                years++;
            }
        }
        
    }

    // Update is called once per frame
    public void Update()
    {
        text.text = "The volume of your build is:" + Volume + "\n" +
            "Which means your build is more likely to look like:" + size + "\n" +
            "The land price is estimated to be:" + LandPrice + "\n" +
            "Which means the total cost of this project will be:" + initCost + "\n" +
            "The uptake yearly cost is roughly:" + yearlyCost + "\n" +
            "The yearly gain of this project using your esimate is:" + yearlyGain + "\n" +
            "Which means it will take youghly:" + years + " Years to return your investment";

    }
}
