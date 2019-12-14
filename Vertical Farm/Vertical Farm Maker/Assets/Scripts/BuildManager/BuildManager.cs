using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BuildManager : MonoBehaviour {

    public GameObject foundation;
    public GameObject wall;
    public GameObject celing;

    public BuildSystem buildSystem;


    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.H) && !buildSystem.isBuilding)
        {
            buildSystem.NewBuild(foundation);
        }
    }

}
