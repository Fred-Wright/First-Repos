using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class QuestControl : MonoBehaviour
{
    public GameObject TransText;
    public GameObject QuestOneText;
    public GameObject QuestTwoText;
    public GameObject QuestThreeText;
    public GameObject QuestFourText;
    public GameObject QuestFiveText;

    public GameObject wField;
    public GameObject lField;
    public GameObject hField;
    public GameObject landField;
    public GameObject ProduceField;
    public GameObject ThreeYes2;
    public GameObject ThreeNo2;
    public bool three;
    public GameObject FourYes2;
    public GameObject FourNo2;
      public bool four;

    public float width;
    public float length;
    public float height;
    public float landPrice;
    public float produce;
    int elecCost;



    float finalCost;


    public int counter = 0;

    //button to progress
    public void OnPressPlus()
    {
        counter++;

        if (counter == 1)
        {
            LTransSlide();
            QuestOne();
        }
        if (counter == 2)
        {
            LQuestOne();
            QuestTwo();
        }

        if (counter == 3)
        {
            LQuestTwo();
            QuestThree();
        }

        if (counter == 4)
        {
            LQuestThree();
            QuestFour();
        }

        if (counter == 5)
        {
            LQuestFour();
            QuestFive();
        }
        if (counter == 6)
        {
            Calculate();
            SceneManager.LoadScene("Game");
        }

    }

    
    //button to go back
    public void OnPressMinus()
    {
        counter--;
        if (counter == -1)
        {
            SceneManager.LoadScene("MainMenu");
        }
        if (counter == 0)
        {
            TransSlide();
            LQuestOne();
        }
        if (counter == 1)
        {
            QuestOne();
            LQuestTwo();
        }
        if (counter == 2)
        {
            QuestTwo();
            LQuestThree();
        }
        if (counter == 3)
        {
            QuestThree();
            LQuestFour();
        }
        if (counter == 4)
        {
            QuestFour();
            LQuestFive();
        }
       
    }

    //appends float values from inputs from inputs
    public void WidthText(string width1)
    {
        width = float.Parse(width1);
    }
    public void LengthText(string length1)
    {
        length = float.Parse(length1);
    }
    public void HeightText(string Height1)
    {
        height = float.Parse(Height1);
    }

    public void LandText(string Land1)
    {
        landPrice = float.Parse(Land1);
        if (landPrice == 0)
        {
            landPrice = 6979;
        }
    }

    public void ProduceText(string pro1)
    {
        produce = float.Parse(pro1);
    }

    public void ThreeYes(string yes)
    {
        three = true;
        LQuestThree();
        QuestFour();
        counter++;
    }

    public void ThreeNo(string no)
    {
        //calculate cost of steel structure to house the farm using dimensions
        three = false;
        LQuestThree();
        QuestFour();
        counter++;
    }

    public void FourYes(string yes1)
    {
        four = true;
        LQuestFour();
        QuestFive();
        counter++;
    }

    public void FourNo(string no1)
    {
        //assigns elecCost depending of size of structure;
        four = false;
        LQuestFour();
        QuestFive();
        counter++;
    }



    //all the transitions in question 
    public void TransSlide()
    {
        TransText.SetActive(true);
    }
    public void LTransSlide()
    {
        TransText.SetActive(false);
    }

    public void QuestOne()
    {
        QuestOneText.SetActive(true);
        wField.SetActive(true);
        lField.SetActive(true);
        hField.SetActive(true);
    }

    public void LQuestOne()
    {
        QuestOneText.SetActive(false);
        wField.SetActive(false);
        lField.SetActive(false);
        hField.SetActive(false);
    }
    public void QuestTwo()
    {
        QuestTwoText.SetActive(true);
        landField.SetActive(true);
    }
    public void LQuestTwo()
    {
        QuestTwoText.SetActive(false);
        landField.SetActive(false);
    }
    public void QuestThree()
    {
        QuestThreeText.SetActive(true);
        ThreeYes2.SetActive(true);
        ThreeNo2.SetActive(true);
    }
    public void LQuestThree()
    {
        QuestThreeText.SetActive(false);
        ThreeYes2.SetActive(false);
        ThreeNo2.SetActive(false);

    }
    public void QuestFour()
    {
        QuestFourText.SetActive(true);
        FourYes2.SetActive(true);
        FourNo2.SetActive(true);
    }
    public void LQuestFour()
    {
        QuestFourText.SetActive(false);
        FourYes2.SetActive(false);
        FourNo2.SetActive(false);
    }
    public void QuestFive()
    {
        QuestFiveText.SetActive(true);
        ProduceField.SetActive(true);
    }
    public void LQuestFive()
    {
        QuestFiveText.SetActive(false);
        ProduceField.SetActive(false);
    }

    public void Calculate()
    {
        //Build volume
        float Volume = width * length * height;
        QuestResults.Volume = Volume;
        //conversion of acre to m^2
        float finLandPrice = (landPrice / 4046) * width * length;
        QuestResults.LandPrice = finLandPrice;
        //total cost of bulding housing structure
        float totalInitCost = 0;
        if(three == true)
        {
            totalInitCost = finLandPrice + (Volume * 280);
        }
        if (three == false)
        {
            totalInitCost = finLandPrice + (Volume * 622);
        }
        QuestResults.initCost = totalInitCost;
        float yearlyCost = 0;
        if (four == true)
        {
            yearlyCost = 0;
        }
        //only the cost of electricity
        if (four == false)
        {
            yearlyCost = Volume * 2f; //1.6 for ele, 0.4 for water
        }
         //after long calc's (of electricity)
        //originally had cosat of water per year, but study shows it is recylable
        QuestResults.yearlyCost = yearlyCost;
        float YearlyProduce = Volume * 100 * 0.7f; //1x1 yeilds 3.9kg per year, capible of holding 3 sets per meter high
        float yield = YearlyProduce * produce;
        float yearlyGain = yield - yearlyCost;
        QuestResults.yearlyGain = yearlyGain;
       


    }
}
